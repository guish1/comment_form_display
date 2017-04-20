(function ($) {
    Drupal.behaviors.personnalizeCkeditor = {
        attach: function(context, settings) {
            if ($('[id^="comment-form-display-title-"]').length > 0) {
                //$('#edit-comment-body-format, #switch_edit-comment-body-value').remove();
            }
        }
    };
    Drupal.behaviors.addCtoolsClass = {
        attach: function(context, settings) {
            if(!$('.ctools-modal-content').hasClass('ctools-modal-dialog')) {
                $('.ctools-modal-content').addClass('ctools-modal-dialog');
            }
        }
    }
})(jQuery)
