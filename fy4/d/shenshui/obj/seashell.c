#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name("����", ({ "sea shell" , "shell"}) );
    	set_weight(5000);
    	set_max_encumbrance(8000);
    	set("no_get", 1);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("prep", "in");
        	set("unit", "��");
        	set("long",  "һ���޴�ĺ��������İ��ǽ��ա����ƺ������������������������죩 \n");
    	}
    	::init_item();
}

void init()
{
   	add_action("do_pull", "pull");
}

int do_pull(string arg){
   	object me, shark, dia, shark1;
    	int num, i;
    	
    	me = this_player();
    	if(me->is_busy()){
        	return notify_fail("������æ��\n");
    	}
    	if(me->is_fighting()){
        	return notify_fail("�����ȴ�����˵�ɡ�\n");
    	}
    	if(!arg || arg != "shell" && arg != "sea shell"){
        	return notify_fail("��Ҫ��ʲô��\n");
    	}    
    	if(!query("shark_came")) {
        	tell_object(me, HIY"����׼��������������Ȼ�е���Χˮ����Ѱ�����ɶ����������к������ס�����\n"NOR);
        	message_vision(HIW"\n    ��������軺�������˹�����\n"NOR, me);
        	num = me->query("����B/��ɽ_�ƺ�") +2;
        	for (i=0;i<num;i++) {
        	       	shark1 = new(AREA_SHENSHUI"npc/shark");
        		shark1 -> move(environment(this_object()));
        	}	
        	set("shark_came", 1);
    	} else if(present("big white shark", environment(me))){
        	tell_object(me, "�㻹���ȵ��Ĵ����ɣ�\n");
    	}else {
        	message_vision("$N�������������� \n", me);
        	message_vision("�����ܵ����������Ǻ�Ȼ�����һ��һ�ϡ����� \n", me);
        	message_vision("һ��ǿ����ˮ���Ӱ���������󺣰�һ�»������һ������Ķ����������������\n", me);

//        	if(me->query("����B/��ɽ_�ƺ�") && !me->query("stone_mark/bstone")) {
			      	
        	message_vision(HIC"һ�������ʯͷ����$N���µ�ɳ���ϡ�\n"NOR, me);       
	        dia = new("/obj/specials/stone/bstone");
        	dia->move(environment(this_object()));
        	REWARD_D->riddle_done(me,"�̺�����",200,1);
//	You can get as many as you want.        	
/*        	} else {
        		message_vision(HIC"һ�����⻬�뺣�����\n"NOR, me);
        	}*/
        	destruct(this_object()); 
    	}
    return 1;
}