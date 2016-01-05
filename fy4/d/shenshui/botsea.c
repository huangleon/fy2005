#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
������һƬ���������������������������������뵽���յ�ҹ�ա�����������
һ���׵�ɳ�����鳤��ɺ���Ľ�ʯɢ����ɳ���ϣ��᳤�ĺ���΢΢��ҡ���ţ�ż
���м���С���ι���ȴ���ܴ���������ļš�
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"midsea", 
    	]) );
    	set("item_desc",([
        	"sand" : "��׵�ϸɳ���ں��ף������ƺ���ʲô������\n", 
        	"ɳ" : "��׵�ϸɳ���ں��ף������ƺ���ʲô������\n", 
    	]) );
    	set("no_fly",1);
    	set("count",1);
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-90);
	set("underwater",100);
	set("water_damage",20);
    	setup();
}

void init(){
    	
    	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
    	add_action("do_search", "search");
    	if(!random(20)){
        	call_out("see_light", 3, this_player());
    	}
}

int do_search(){
    	object me;
    	me = this_player();
    
    	if(me->is_busy()) {
        	return notify_fail("������æ��\n");
    	}
    	if(me->is_fighting()){
        	return notify_fail("�����ȴ�����˵�ɡ�\n");
    	}
    	message_vision("$N�ں�����ϸ��Ѱ��\n", me);
    	me->start_busy(2);
    	call_out("result", 4, me);
    	return 1;
}

int result(object me) {
    	object seashell;
    	if(environment(me) == this_object()){
        	if(!random(5) && !present("sea shell", this_object()) && query("count")) {
	            	tell_object(me, "\n���Ȼ����һ���󺣰���\n");
	            	message_vision(HIC"\n��ֻ����һ˿��ӨӨ�Ĺ����ǰһ�����š�\n"NOR, me);
	            	message_vision("����΢΢����һ�£����ǽ��������ˡ�\n", me);
	            	seashell = new(__DIR__"obj/seashell");
	            	seashell->move(this_object());
	            	set("count",0);
	            	return 1;
        	}
        	tell_object(me, "��ʲôҲû�з��֡�\n");
    	}
    return 1;
}

int see_light(object me){
    	if(environment(me) == this_object()) {
        	message("vision", HIC"\nһ����ӨӨ��΢��һ�����š�\n"NOR, environment(me));
    	}
}

int valid_leave(string dir){
	object me;
    	me = this_player();
    	message_vision("$N���˵���������ȥ��\n", me);
    	return 1;
}

void reset(){
	::reset();
	set("count",1);
}

