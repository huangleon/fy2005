#include <ansi.h>
inherit ITEM;
void move_shenshui(object player);
void create(){

    set_name("蒲团", ({"putuan", "蒲团" }) );
    set_weight(2000);
    set_max_encumbrance(8000);
    set("no_get", 1);

    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
    set("unit", "个");
    set("long", "的表面被磨得十分光滑，看来经常有人坐在这里。\n");
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
                set("long", query("sitdown_person")->name()+"盘膝坐在蒲团之上。\n");    
        }else
        {
                set("long", "蒲团的表面被磨得十分光滑，看来经常有人坐在这里（sitdown/standup）。\n");
        }
        return 0;
}

int do_sitdown(){
        
        object me, laoni;
        mapping who;
        int i,j,amount;
        
        me = this_player();
        if(me==query("sitdown_person") || me->query_temp("state/sit")){
                return  notify_fail("你已经坐下了呀！？\n");            
        }
        if(query("sitdown_person")&&present(query("sitdown_person"),environment(this_object()))){
                return notify_fail("蒲团上都已经坐了人。。。\n");
        }
        message_vision("$N在蒲团上盘膝坐了下来。\n", me);
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
                message_vision("$N从蒲团上站起身来。\n",me);
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
	 	message_vision(HIB"青衣老尼似乎瞥了$N一眼，衣袖一动，$N座下的蒲团忽然一翻，$N忽然平地消失了。\n"NOR,player);
	 	room = find_object(AREA_SHENSHUI"huoyan");
	 	if (!room) room = load_object(AREA_SHENSHUI"huoyan");
	 	player->move(room);
	 }
}
*/
