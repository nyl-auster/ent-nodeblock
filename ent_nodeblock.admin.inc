<?php
/**
 * Admin config form for ent nodeblock
 */

function ent_nodeblock_config_form($form) {
  $form = array();
  $form['ent_nodeblock_content_types'] = array(
    '#title' => 'Content types to convert to drupal blocks',
    '#type' => 'checkboxes',
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('ent_nodeblock_content_types', array())
  );
  return system_settings_form($form);
}