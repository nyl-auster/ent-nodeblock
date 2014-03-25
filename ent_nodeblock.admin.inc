<?php
/**
 * Admin config form for ent nodeblock
 */

function ent_nodeblock_config_form() {

  $form = array();
  $node_types = node_type_get_names();
  $conf = variable_get('ent_nodeblock', array());

  // save all our variables as an array in variable tables with #tree => TRUE
  $form['ent_nodeblock'] = array('#tree' => TRUE);

  $form['ent_nodeblock']['content_types'] = array('#type' => 'fieldset', '#title' => t('Content types'));
  foreach ($node_types as $type => $name) {
    $form['ent_nodeblock']['content_types'][$type] = array('#type' => 'fieldset', '#title' => $name);

    $enabled = isset($conf['content_types'][$type]['enabled']) ? $conf['content_types'][$type]['enabled'] : 0;

    $form['ent_nodeblock']['content_types'][$type]['enabled'] = array(
      '#prefix' => $enabled ? '<div style="color : green ">' : '<div style="font-weight : bold; color : red">',
      '#type' => 'checkbox',
      '#title' => t('Enabled'),
      '#default_value' => $enabled,
      '#suffix' => '</div>',
    );

    $hide_node_title = isset($conf['content_types'][$type]['hide_node_title']) ? $conf['content_types'][$type]['hide_node_title'] : 0;
    $form['ent_nodeblock']['content_types'][$type]['hide_node_title'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide node title'),
      '#default_value' => $hide_node_title,
    );
  }

  return system_settings_form($form);
}
