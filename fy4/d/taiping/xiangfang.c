inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "��վ�᷿");
        set("long", @LONG
�᷿��һ���ֳ�����խ���ֵ͵����ӣ�һ�������Ļ���ľ���Ӵ���ͷ�ڵ���һ
ͷ�����������žɵÿ�����ԭ����ɫ��̨�����������ϵ���ͨ���Ĳ;ߺ���ʳ����
����Щ�ѿںܶ�ı��ش����������Ǹ�������������ЪϢ֮����
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"yizhan",
	]));
        set("objects",([
 		__DIR__"npc/yayi": 1,
 		__DIR__"npc/yayi1":1,
        ])  );         
        set("item_desc", ([
		"����":	"һ�������Ļ���ľ���Ӵ���ͷ�ڵ���һͷ�����ϰڵ���ͨ���Ĳ;ߺ���ʳ��
����������ЪϢһ�󣨣��������\n",
	 	"table":"һ�������Ļ���ľ���Ӵ���ͷ�ڵ���һͷ�����ϰڵ���ͨ���Ĳ;ߺ���ʳ��
����������ЪϢһ�󣨣��������\n",
	 ]));
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


void init(){
	add_action("do_rest","rest");
}


int do_rest(){
	object yayi,me;
	me=this_player();
	yayi=present("yayi",this_object());
	if (me->query("class")!="official" && objectp(yayi))
		return notify_fail("����˵�������ֻ���ٲ�ЪϢ�����������뿪����\n");
	me->start_busy(1);
	message_vision(WHT"$N�����������̻��ʵسԺ�������\n"NOR,me);
	call_out("done",2,me);
	return 1;
}


int done(object me) {
	me->set("food",230);
	me->set("water",230);
	message_vision(HIG"$N���˸����ã����������վ��������\n"NOR,me);
	return 1;
}