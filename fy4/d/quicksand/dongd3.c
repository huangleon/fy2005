#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ɳѨ");
	set("long", @LONG
����Խ��Խ�ߣ�������Ȼ�Ǻںڵģ���Χ��ʯҲԽ��Խ�٣��������о��ƺ�
����һ��ɳ��֮�У������������ɳ�ӣ��ռ�Խ��ԽС�����ܵ�ɳǽ����ʱ�Ϳ���
̮�����������ᣬͷ����ʱ����ϸɳ���£�����Ŀ�����Ȼ�о���������ȴ�Ѳ���
��ô���ơ�
LONG
	);
	set("exits", ([ 
  		"northdown" : __DIR__"dongd2",
	]));
    	set("item_desc", ([
    		"sand" : "ɳ����ϸ���������еĸо�һ��������ɳ�����а������¶�����档
���ƺ��������������졡�������\n",
    		"ɳ��" : "ɳ����ϸ���������еĸо�һ��������ɳ�����а������¶�����档
���ƺ��������������졡�������\n",
    	]) );
	set("indoors", "quicksand");
	set("coor/x",-1020);
	set("coor/y",-30);
	set("coor/z",-5);
	setup();
}

void init(){
    	add_action("do_pull", "pull");
}

int do_pull(string arg){
    	object ro;
    	if(!arg || arg != "chain") {
        	return notify_fail("��Ҫ��ʲô��\n");
    	}
    	if (query("exits/up"))
    		return notify_fail("�����Ѿ����ˡ�\n");
    		
    	ro = load_object(__DIR__"desert_entrance");
    	if(NATURE_D->is_day_time()){
        	message_vision("����һ����΢�ĳ���ת����������һ��ɳ�����£�������һ��
���۵Ĺ�â���룬���������������ۡ�\n", this_player());
	 } else {
        	message_vision("
����һ����΢�ĳ���ת����������һ��ɳ�����£����µĿ������������\n", this_player());
    	}
    	if(!objectp(ro)){
        	ro = load_object(__DIR__"desert_entrance");
    	}
    	set("exits/up", __DIR__"desert_entrance");
    	ro->set("exits/down", __DIR__"dongd3");
    	call_out("close_path", 10);
    	return 1;
}


void close_path(){
    	object ro;
	if(!objectp(ro)){
        ro = load_object(__DIR__"desert_entrance");
    	}
    	if(query("exits/up")){
        	message("vision", "����һ����΢�ĳ���ת����������һ�����������֮�С�\n", this_object());
        	delete("exits/up");
    	}
    	if(ro->query("exits/down")){
        	ro->delete("exits/down");
    	}
}
