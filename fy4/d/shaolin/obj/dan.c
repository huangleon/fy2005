// medicine.c

inherit ITEM;

void create()
{
	set_name("С����",({"xiaodan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һ�豻��Ϊ����֮����С������ֻ��������С��\n");
	    set("unit","��");
	    set("value", 200);
	}
}

void init()
{
  if(this_player()==environment())
	add_action("apply_medicine",({"yong","use"}));
}

int apply_medicine(string arg)
{
	object victim;
	object me = this_player();
	
	if(!arg || !objectp(victim=present(arg,environment(this_player()))))
		victim = this_player();
		
	if(this_player()->is_fighting() || environment(victim)->query("no_magic"))
	    	return notify_fail("���ڲ�����ҩ����\n");
	    	
        if (userp(me) && me!= victim)
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
	
    if(victim != this_player() && 
       	random( victim->query("combat_exp")) > this_player()->query("combat_exp"))
	{
		message_vision("$N��$n�ȵ����󵨣����Ҷ����¶�����\n",victim,this_player());
		victim->kill_ob(this_player());
		this_player()->kill_ob(victim);
		this_player()->start_busy(2);
	} else {
		if (victim != this_player())
			tell_object(this_player(),"����ָ�׽�С������ɷ�ĩ������ص���"+ victim->name()+"���ϡ�\n");
		else 
			tell_object(this_player(),"����ָ�׽�С������ɷ�ĩ������ص����Լ����ϡ�\n");
		victim->apply_condition("unknown",random(20)+5);
	}
	destruct(this_object());
	return 1;
}


