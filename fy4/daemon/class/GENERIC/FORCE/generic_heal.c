

int general_heal(object me, object target, string limit, int amount, int cost, string msg_self, string msg_target, string type) {
	
		if( me->is_fighting() || target->is_fighting()) {
        	tell_object(me,"ս�����˹����ˣ�������\n");
        	return 1;
        }
  
  		if (!objectp(target))	target = me;
  			      
        switch (limit) {
        	case "party":	if (target != me && !me->team_member(target)) {
        						tell_object(me, "��ֻ�ܸ�ͬһ�����е������ˡ�\n");
        						return 1;
        					}
        					break;
        	case "others":	if (me == target) {
        						tell_object(me, "��ֻ���ô��ķ������˵��ˡ�\n");
        						return 1;
        					}
        					break;
        	case "self":	
        	default:		if (me != target) {	
        						tell_object(me, "��ֻ���ô��ķ����Լ����ˡ�\n");
        						return 1;
        					}
        					break;
        }
       
       	if (!COMBAT_D->legitimate_heal(me,target)) {
			tell_object(me, "�㲻�������ʹ�ô������ľ���������ɱ���ƣ�\n");	  
            return 1;
        }
            
		if(me->query("force") < me->query("max_force")) {
        	tell_object(me, "����ʱ������Ҫ���������ֵ���塣\n");
        	return 1;
        }
       
       	if (target->query("eff_"+ type)>= target->query("max_"+type)) {
       		tell_object(me,"�����Ѿ�����Ҫʹ�ô������ķ��ˡ�\n");
       		return 1;
       	}
       	
       	 
		if (me->query("force")< cost) {
			tell_object(me, "������Ҫ"+cost+"��������\n");
			return 1;
		}
		me->add("force", -cost);
					
		if (target != me)
			message_vision(msg_target, me, target);
		else
			message_vision(msg_self, me);
		tell_object(target,"������ƺ���һЩ��\n");

		amount = amount* (100 + me->query_skill("prescription",1)/4)/100;
		amount = COMBAT_D->magic_modifier(me, target, type, amount);
		target->receive_curing(type, amount);

		return 1;
}

