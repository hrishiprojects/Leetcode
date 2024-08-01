bool FloydWarshallAlgorithm(DirectedGraph *g, Distances *distances){
  double u, v, k, i, j;
  Node *n;
  Edge *e;
  Target *t, *ij, *ik, *kj;
  bool success;

  success = true;

  for(u = 0.0; u < (double)g->nodes->size(); u = u + 1.0){
    n = g->nodes->at(u);

    for(j = 0.0; j < (double)n->edge->size(); j = j + 1.0){
      e = n->edge->at(j);
      v = e->nodeNr;

      t = distances->from->at(u)->to->at(v);
      t->length = e->weight;
      t->lengthSet = true;
      t->next = v;
    }
  }

  for(v = 0.0; v < (double)g->nodes->size(); v = v + 1.0){
    t = distances->from->at(v)->to->at(v);
    t->length = 0.0;
    t->lengthSet = true;
    t->next = v;
  }

  for(k = 0.0; k < (double)g->nodes->size() && success; k = k + 1.0){
    for(i = 0.0; i < (double)g->nodes->size() && success; i = i + 1.0){
      for(j = 0.0; j < (double)g->nodes->size() && success; j = j + 1.0){
        ij = distances->from->at(i)->to->at(j);
        ik = distances->from->at(i)->to->at(k);
        kj = distances->from->at(k)->to->at(j);

        if( !ij->lengthSet  && ik->lengthSet && kj->lengthSet){
          ij->length = ik->length + kj->length;
          ij->lengthSet = true;
          ij->next = ik->next;
        }else if(ij->lengthSet && ik->lengthSet && kj->lengthSet){
          if(ij->length > ik->length + kj->length){
            ij->length = ik->length + kj->length;
            ij->next = ik->next;
          }
        }

        if(i == j){
          if(ij->length < 0.0){
            success = false;
          }
        }
      }
    }
  }

  return success;
}
