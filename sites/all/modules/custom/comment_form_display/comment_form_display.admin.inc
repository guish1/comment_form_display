<?php 

function comment_form_display_admin() {
  return drupal_get_form('comment_form_display_form');
}

// form admin display mode choice
function comment_form_display_form($form, $form_state) {

    $prefix = '<h1>Comment Form Display</h1>';
    $prefix .= '<h4>' . t('Display mode') . '</h4>';
    $prefix .= '<p>' . t('You can choose which display you want for each comments links.'). '</p>';
    $prefix .= '<p>' . t('URL takes place automatically when you select a display');
        $prefix .= ' : ';
        $prefix .= '<ul>';
            $prefix .= '<li>' . ucfirst(t('default'));
                $prefix .= '<br>';
                $prefix .= t('The default display uses the standard Comment invokation as to know, a redirection in a specific page.');
            $prefix .= '</li>';
                $prefix .= '<li>' . t('Modal : comment/nojs/%comment_id/%action');
                $prefix .= '<br>';
            $prefix .= t('The action form is loaded in a pop up and updated without reloading the comment.');
            $prefix .= '</li>';
        $prefix .= '</ul>';
    $prefix .= '</p>';
    $form['#prefix'] = $prefix;
    
    $links = comment_form_display_links();
    foreach ($links as $key => $l) {
        $lstrtoupper = strtoupper($l);
        $form[$l] = array(
            '#title' => t($lstrtoupper),
            '#type' => 'select',
            '#default_value' => variable_get('config_form_display_display_mode_'.$l),
            '#options' => comment_form_display_widget(true)
        );
    };
    $form['submit'] = array(
    '#type' => 'submit',
    '#default_value' => t('Save'),
    '#submit' => array('comment_form_display_form_submit')
    );
    
    return $form;
}

function comment_form_display_form_validate($form, &$form_state) {
    $links = comment_form_display_links();
    $widgets = count(comment_form_display_widget(false));
    // links value must be 0 or 1 (number of widget)
    foreach ($links as $key => $l) {
        if ($form_state['input'][$l] > $widgets - 1) {
            form_set_error($l, t('A forbidden choice has been done.'));
        }
    }
}

function comment_form_display_form_submit($form, $form_state) {
  $query = db_update('config_form_display_display_mode')
    ->fields(array(
        'display_delete' => $form_state['input']['delete'],
        'display_edit' => $form_state['input']['edit'],
        'display_reply' => $form_state['input']['reply']
    ))
    ->execute();
  if ($query) {
    variable_set('config_form_display_display_mode_delete', $form_state['input']['delete']);
    variable_set('config_form_display_display_mode_edit', $form_state['input']['edit']);
    variable_set('config_form_display_display_mode_reply', $form_state['input']['reply']);
    
    cache_clear_all();
    
    drupal_set_message(t('Config display changed successfully.'), 'status');
  }
}