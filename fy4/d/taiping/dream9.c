#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ħ��");
        set("long", @LONG
���Х����Ʈ�ɣ������������ֿ�ʼ���ǽ�۵ĺ����ֿ�ʼ�������������
ǰ����һ������ס�����Ϸ������������ԡ��ϵ���׵ľ�ͷ����Ȼ��һƬ����
һ���޼ʵ�����ˮ��������ɫ��Ҳ��������ɫ���Ǻ�ɫ����þ�������Ѫ������
��˵��һƬ��������˵����һƬѪ����һ�����ģ�ȴҲû��������ӡ������ϸ�
����û����գ�ֻ�з���������뺮������������˼�ĺ��󡣰���ͣ��һ��ľ
�ţ����ѵ����Ƕɹ�ħ����ħ�ۡ�
LONG
        );
        set("exits", ([ 
		"north":  __DIR__"dream8",
	]));
	set("objects", ([
		
    	]) );
        set("no_fly",1);
        set("item_desc", ([
		"boat": "һҶľ�ţ���Ѫ����Ʈ����Ҳ�����������ȥ��(jumpto)\n",
		"ľ��": "һҶľ�ţ���Ѫ����Ʈ����Ҳ�����������ȥ��(jumpto)\n",
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init() {
	add_action("do_jump","jumpto");
}


int do_jump(string arg) {
	object me, room;
	me=this_player();
	
	if (!arg || (arg!="boat" && arg!="ľ��")) {
		tell_object(me,"��Ҫ���Ķ�����\n");
		return 1;
	}
	
	message_vision(WHT"$Nһ��������ħ����Ծ�䡣\n"NOR,me);
	message_vision(HIR"����ħ�۾�ͻȻ��ʧ��$N��������һƬѪ��֮�У�Ѫ����Ŀ����Ѫ��\n"NOR,me);
	tell_object(me,WHT"ɲ��֮�䣬��ֻ���Լ���׹��һƬ����֮�С���Ŀ���ˣ���Ŀ�Ѳ���Ѫ������һƬ�ڰ���\n"NOR);
	tell_object(me,BLU"                �޾��ĺڰ���\n"NOR);
	room=find_object(AREA_TAIPING"basement");
	if (!room)
		room=load_object(AREA_TAIPING"basement");
	me->move(room);
	me->unconcious();
	return 1;
}
	