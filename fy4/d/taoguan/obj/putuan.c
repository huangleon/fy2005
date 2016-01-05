#include <ansi.h>
inherit ITEM;
void move_shenshui(object player);
void create(){

    set_name("����", ({"putuan", "����" }) );
    set_weight(2000);
    set_max_encumbrance(8000);
    set("no_get", 1);

    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
    set("unit", "��");
    set("long", "�ı��汻ĥ��ʮ�ֹ⻬���������������������\n");
    set("value", 10);
    }
    ::init_item();
}

void init()
{
        add_action("do_sitdown", "sitdown");
        add_action("do_standup", "standup");
        add_action("do_look","look");
}

int do_look()
{
        object sitdown_person;
        if (query("sitdown_person") && present(query("sitdown_person"),environment(this_object())))
        {
                set("long", query("sitdown_person")->name()+"��ϥ��������֮�ϡ�\n");    
        }else
        {
                set("long", "���ŵı��汻ĥ��ʮ�ֹ⻬���������������������sitdown/standup����\n");
        }
        return 0;
}

int do_sitdown(){
        
        object me, laoni;
        mapping who;
        int i,j,amount;
        
        me = this_player();
        if(me==query("sitdown_person") || me->query_temp("state/sit")){
                return  notify_fail("���Ѿ�������ѽ����\n");            
        }
        if(query("sitdown_person")&&present(query("sitdown_person"),environment(this_object()))){
                return notify_fail("�����϶��Ѿ������ˡ�����\n");
        }
        message_vision("$N����������ϥ����������\n", me);
        set("sitdown_person", me);
        me->set_temp("state/sit", 1);
//        laoni = present("laoni", environment(this_object()));
//        if ( me->query("class") == "shenshui" && objectp(laoni) && !userp(laoni)) 
//    			call_out("move_shenshui",7, me);    	
        return 1;
}

int do_standup(){
        object me;
        
        me = this_player();
        if(me==query("sitdown_person")){
                message_vision("$N��������վ��������\n",me);
                me->delete_temp("state/sit");
                set("sitdown_person",0);
                return 1;
        }
        return 0;
}

/*
void move_shenshui(object player) {
	 object room;
	 if ( player->query_temp("state/sit") 
	 	&& environment(player) == environment(this_object()) ) {
	 	player->delete_temp("state/sit");
	 	set("sitdown_person",0);
	 	message_vision(HIB"���������ƺ�Ƴ��$Nһ�ۣ�����һ����$N���µ����ź�Ȼһ����$N��Ȼƽ����ʧ�ˡ�\n"NOR,player);
	 	room = find_object(AREA_SHENSHUI"huoyan");
	 	if (!room) room = load_object(AREA_SHENSHUI"huoyan");
	 	player->move(room);
	 }
}
*/
