(function ($) {
    var links = [];
    links[1] = 'delete';
    links[0] = 'edit';
    links[2] = 'reply';
    
    Drupal.behaviors.addSelectorToAjaxCommandHtmlEdit = {
        attach: function(context, settings) {
            if($('#comments').length > 0 && $('body').hasClass('logged-in')) {
                $('[id^="comment"]').each(function() {
                    $(this).next().find('h3').attr('id', 'comment-form-display-title-'+$(this).attr('id'));
                    $(this).next().find('.content > p').attr('id', 'comment-form-display-body-'+$(this).attr('id'));
                })
            }
        }
    };
    Drupal.behaviors.addClassAction = {
        attach: function(context, settings) {
            for(var i = 0; i < links.length; i++) {
                if ($('#comment-form-display-modal-'+links[i]+'-form').length > 0) {
                    $('#comment-form-display-modal-'+links[i]+'-form').parents('.modal-content').addClass('comment-form-display-'+links[i]);
                }
            }
        }
    };
})(jQuery)
