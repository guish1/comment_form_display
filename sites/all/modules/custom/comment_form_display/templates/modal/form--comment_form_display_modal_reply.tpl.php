<div class="content">
    <?=t('Reply to comment on content');?> : <a href="<?=($form['#node']->language != 'und') ? '/'.$form['#node']->language : '';?>/<?=drupal_get_path_alias('node/'.$form['#node']->nid);?>"><?=$form['#node']->title;?></a>
    <blockquote>
      <p><?=$form['#comment_reply']->comment_body['und'][0]['value'];?></p>
      <footer><?=ucfirst($form['#comment_reply']->subject);?> <cite title="author"><?=$form['#comment_reply']->name;?></cite></footer>
    </blockquote>
</div>
<?php  
    print drupal_render_children($form);
?> 