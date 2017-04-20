<div class="content">
    <div>
        <?=t('Are you sure you want to delete the comment ?');?>
        <br>
        <?=t('All replies to this comment will be lost.');?>
    </div>
    <blockquote>
      <p><?=$form['#comment_delete']->comment_body['und'][0]['value'];?></p>
      <footer><?=ucfirst($form['#comment_delete']->subject);?> <cite title="author"><?=$form['#comment_delete']->name;?></cite></footer>
    </blockquote>
</div>
<?php  
    print drupal_render_children($form);
?> 