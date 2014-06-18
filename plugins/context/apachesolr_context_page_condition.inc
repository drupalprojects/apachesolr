<?php
/**
 * @file
 * Context integration for Apachesolr.
 */

/**
 * Context condition class.
 */
class apachesolr_context_page_condition extends context_condition {
  function condition_values() {
    $values = array();
    foreach (apachesolr_search_load_all_search_pages() as $page) {
      $values[$page['page_id']] = check_plain($page['label']);
    }
    return $values;
  }

  function execute($search_page) {
    foreach ($this->get_contexts($search_page['page_id']) as $context) {
      $this->condition_met($context, $search_page['page_id']);
    }
  }
}
