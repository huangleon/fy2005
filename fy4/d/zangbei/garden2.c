inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ջ�԰��");
        set("long", @LONG
�ջ�԰�ܴ󣬾ջ�԰����÷��԰����ĵ����Ǿޱ����ҩ���軨������������԰��
���еĻ�԰�������˭Ҳ��֪������ռ�˶��ٵأ�ֻ֪��һ���˾��ߵúܿ�Ҳ����
һ����������Ƭ����һȦ����԰��ܾ���û���ˣ�û���������ϲ��Ļ�԰һ����
�����ӵģ�����ֻҪһ�߽�ȥ��ÿ�������ﶼ�������˺�Ȼ���֣�ÿ���˶�����Ҫ
�������
LONG
        );
        set("exits", ([ 
		"southeast" :   	__DIR__"garden1",
		"north" : 	__DIR__"groom4",
		"southwest":	__DIR__"garden3",
	]));
	
	set("item_desc", ([
        	"�ջ�":	"�����＾��԰����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
        	"flower": "�����＾��Ժ����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n",
    	]));
    	
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1320);
        set("coor/y",970);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}


void init() {
	add_action("do_pull","pull");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(),"԰����ľջ����������дУ�������һ�춼�����н����\n");
	return 1;
}


int do_pull(string arg) {
	object me=this_player();
	object xiaohe;
	
	if (arg== "flower" || arg == "�ջ�") {
		tell_object(me,YEL"�����ȥ���ְ���һ��ջ����ջ�����һ�Σ�����������\n\n"NOR);
		return 1;
	}
	return notify_fail("�����/��ʲô��\n");
}
