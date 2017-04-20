(function ($) {
    Drupal.behaviors.addSelectorToAjaxCommandHtmlReply = {
        attach: function(context, settings) {
            if($('#comments').length > 0 && $('body').hasClass('logged-in')) {
                $('a[id^="comment"]').each(function() {
                    var next = $(this).next().next();
                    if (!next.hasClass('indented')) {
                        $(this).next().after('<div class="indented" id="comment-post-'+$(this).attr('id')+'"></div>');
                    } else {
                        next.attr('id', 'comment-post-'+$(this).attr('id'));
                    }
                })
            }
        }
    };
    // this function uses "indented" class above to complete the render when it's not completed
    Drupal.behaviors.indentedUpdated = {
        attach: function(context, settings) {
            $('body').delegate('.indented', 'change', function() {
                // by default, links are not created, need to rebuild it
                $('.comment-by-viewer').each(function() {
                    if (!$(this).find('ul.links')) {
                
                    }
                })
            })
        }
    };
})(jQuery)
