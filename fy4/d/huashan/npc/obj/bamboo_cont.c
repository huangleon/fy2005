// Disabled by Silencer@fy2005 workgroup

#include <ansi.h>
inherit ITEM;
int Gone();
void create()
{
	set_name("��Ͳ", ({ "zhu tong", "bamboo" }) );
	set_weight(200);
	set_max_encumbrance(1000);
	set("prep","in");
	set("is_open", 0);
	set("have_snake", 0);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "��");
	    set("long", "һ����ɵ�С��Ͳ����Ͳ��һͷ���ŵ������Ϻ�ɫ��\n");
	    set("value", 1);
	}
	::init_item();
}

/*
int is_container() { return 1; }

void init(){
	if(this_player() == environment()){
		add_action("do_use", "use");	
		add_action("do_open", "open");
		add_action("do_close", "close");
		add_action("do_train", "train");
	}
}

int Gone(){
	set("have_snake", 0);
	delete("owner");
	delete("trained");
	set_name("��Ͳ", ({ "zhu tong", "bamboo" }) );
	set("long", "һ������ɫ��С��Ͳ�����Դ�һͷ�򿪡�\n");
	return 1;
}

int do_train(string arg){
    	object me, obj;
    	obj = this_object();
    	me = this_player();
    	if (!present(obj,me) || !query("have_snake")){
            return 0;
    	}
    	
    	if (arg != "snake" && arg != "С��"){
            return 0;
    	}
    	
    	if (query("trained"))
    		return notify_fail("С���Ѿ�ѵ�����ˡ�\n");
    		
    	if (me->query_skill("animal-training",1) < 150){
            	return notify_fail("���ѵ�����������ߣ�\n");
    	}
    	if(query("train_needed") > 0) {
    		message_vision("$NС�ĵĴ���Ͳ���ĵ�ѵ��С��,С���ƺ�������$N�Ļ���\n",me);
    		add("train_needed", -1);
    	} else {
	    	tell_object(me, "С���ƺ���������Ļ�������������������ʱ׼���������\n");
	    	set("trained",1);
	    	set("owner", me->name()); 
	    	
			REWARD_D->riddle_done( me, "��������Ͳ", 20, 1);
			
    		set_name(MAG"����Ͳ"NOR, ({ "shetong" }) );
		set("long","һ��װ��С�ߵ���Ͳ���������������������룩��\n");
    		add_action("do_attack", "attack");
    	}
    return 1;
}

int do_attack(string arg){
	object me, obj, target;
	int lvl;
	obj = this_object();
	me = this_player();
	lvl = (int)me->query_skill("animal-training");

	if(!query("trained")){
		return notify_fail("С���������û�з�Ӧ��\n");
	}
	if(!arg) {
		return notify_fail("��Ҫ����˭��\n");
	}
	
	
	target = find_living(arg);
	if(!target || environment(target) != environment(me)) {
		return notify_fail("����û������ˡ�\n");
	}
	
	if(query("owner") != me->name() ) {
		message_vision(MAG"$NС�ĵ�š����Ͳ��ֻ��һ���Ϲ�ɳ���ɲ�Ǽ䲻������Ӱ��\n"NOR, me);
		Gone();
		return 1;
	}
	
	if (me->is_busy())
		return notify_fail("��������æ��û�մ���Ͳ��\n");
	
	if (target==me)
		return notify_fail("����ɱ��\n");
	
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, target)) {
		if (stringp(target->query("NO_KILL")))
			return notify_fail(target->query("NO_KILL"));
		if (stringp(target->query("NO_PK")))
			return notify_fail(target->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
			
	if(time() - query("time-used") < 3420) {
		return notify_fail("С�߿�������Щή�ң�����ʱ�����ðɡ�\n");
	}
	if(!random(lvl/20)){
		message_vision(MAG"$N�ó�һ����Ͳ��ֻ��һ���Ϲ�ɳ���ɲ�Ǽ䲻������Ӱ��\n"NOR, me);
		Gone();	
	} else {
		message_vision(MAG"$N�����ó�һ����Ͳ��׼"+"$n" +MAG"��ֻ��һ���Ϲ����"+"$n" 
+ MAG"��գ�ۼ��ַ��˻�����\n"NOR, me, target);
		tell_object(target, HIM"��ֻ��������һ�顣\n"NOR);
		if (userp(target)) target->apply_condition("canxia", 10);
			else target->apply_condition("canxia", 30);
		set("time-used", time());
	}
	me->start_busy(3);
	return 1;
}	

int do_close(string arg)
{
        object          me, ob;

        me = this_player();
        ob = this_object();
        if( !arg || (arg != "zhutong" && arg != "zhu tong")) {
                return notify_fail("��Ҫ����ʲô��\n");
        }
        
        if(query("is_open")){
        	message_vision("$N��$n��š����\n", me, ob);
        	ob->set("is_open", 0);
        } else {
        	return notify_fail("��Ͳ�ǹ��ŵġ�\n");
        }
        return 1;
}

int do_open(string arg)
{
    	object me, ob;
    
    	if( !arg || (arg != "zhutong" && arg != "zhu tong")) {
    		return notify_fail("��Ҫ��ʲô��\n");
    	}
    	me = this_player();
    	ob = this_object();
	if(query("have_snake")){
		message("vision", me->name() + "������Ͳ��������ԥ��һ���ַ��˻�ȥ��\n", 
				environment(me), me);
		tell_object(me, "Ҫ�������˿ɲ��ã����ǲ�Ҫ���˰ɡ�\n");
		return 1;
	}
	if(query("is_open")) {
		return notify_fail("��Ͳ�Ѿ��Ǵ򿪵ġ�\n");
	} else {
    	message_vision("$N����Ͳ�򿪡�\n", me, ob);
    	ob->set("is_open", 1);
    }
    return 1;
}

*/