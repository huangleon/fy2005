inherit ROOM;
#include <ansi.h>

int do_look(string arg);

void create()

{
        set("short", "����Ӻ�Ժ");
        set("long", @LONG
��Ժ�����ǵ͵͵���ǽ��ǽ��������������������ż������裬������Ķ�
�黨������Ѥ�á�Ժ�����м���������ľ�˺�һ�������ܣ����Ϻ��Ҹ��ŵ�����һ
��ʮ�������Ů����������üĿ����¶�ŵ����İ��
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"dazuiju1",
	]));
        set("item_desc",([
        	"������":	"�������Ϻ��ҷ���Щ������\n",
        	"ľ��":		"�����и�ľ���ƺ���Щ��֣��㿴��������Ҳ�����㣬�����ƺ���ת�˼��¡�\n",
        	"woodman":	"�����и�ľ���ƺ���Щ��֣��㿴��������Ҳ�����㣬�����ƺ���ת�˼��¡�\n",
        ]));
        
        set("objects", ([
        	__DIR__"npc/pinggu": 1,
	]) );
	
	set("coor/x",50);
    set("coor/y",100);
    set("coor/z",0);
	set("map","eren");
	set("thief",1);
	setup();
	
}


void init(){
	add_action("do_push","push");
}


int do_push(string arg){
		
	object me, pinggu, thief;
	
	me = this_player();
	if (arg == "������") {
		tell_object(me,"�����ܻ��˻Σ��ֻص���ԭ�ء�\n");
		return 1;
	}
	
	if (!arg || (arg!="ľ��" && arg!= "woodman")) {
		tell_object(me,"������ʲô��\n");
		return 1;
	}
	
	if (!query("thief")) {
		tell_object(me,"��������ľ�ˣ����ʲôҲû�з�����\n");
		return 1;
	}
		
	tell_object(me,	"�������������Ǹ���ֵ�ľ�ˣ�ľ���ƺ�������������Ц��������ԭ���Ǹ����ˡ�\n");
	
	thief = new(__DIR__"npc/star_bunny");
	if (!thief)	return 1;
	thief->move(this_object());
	
	if (pinggu = present("tie pinggu")) {
		thief->ccommand("lovelook pinggu");
		pinggu->ccommand("kiss hu yaoshi");
	}
	
	set("thief",0);
	return 1;
}
	
	
void reset(){
	object sikong;
	
	sikong = present("hu yaoshi");
	if (sikong && !sikong->is_fighting()) {
		message_vision("��ҩʦ˵�������������������棬˵����һ�������ˡ�\n",sikong);
		destruct(sikong);			
	}
	set("thief",1);
	::reset();
}
	