<?php
/**
 * Admin config form for ent nodeblock
 */

function ent_nodeblock_config_form() {
  $form = array();
  $conf = ent_nodeblock_get_conf();
  // save all our variables as an array in variable tables with #tree => TRUE
  $form['ent_nodeblock'] = array('#tree' => TRUE);

  foreach (node_type_get_names() as $type => $name) {
    $form['ent_nodeblock'][$type] = array('#type' => 'fieldset', '#title' => $name);
    $form['ent_nodeblock'][$type]['enabled'] = array(
      '#prefix' =>  $conf[$type]['enabled'] ? '<div style="color : green ">' : '<div style="font-weight : bold; color : red">',
      '#type' => 'checkbox',
      '#title' => t('Enabled'),
      '#default_value' =>  $conf[$type]['enabled'];
      '#suffix' => '</div>',
    );
    $form['ent_nodeblock'][$type]['hide_node_title'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide node title'),
      '#default_value' =>  $conf[$type]['hide_node_title'],
    );
  }
  return system_settings_form($form);
}
