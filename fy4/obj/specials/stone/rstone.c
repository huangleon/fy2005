#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"�����൤"NOR, ({"ruby", "red stone"}));
    	set_weight(200);
    	if( clonep() )
       		set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("long", "
һ��������ϼ�ĺ챦ʯ��������Ծ�����ƺ��в�Ϩ�Ļ��档�������õ� 
���ˣ��������յĸо���\n");
        	set("value", 200);
		set("imbue", 1);
    }
	::init_item();
}

void init(){
    	if(this_player() == environment()){
        	add_action("do_wield", "wield");
    	}
}

int do_wield(string arg){
    	object me;
    
    	me = this_player();
    	if(!arg || arg != "ruby"){
        	return 0;
    	}
    	message_vision("$N�Ѻ챦ʯ�������С�\n", me);
    	environment(me)->tell_exit(me);
    	return 1;    
}


