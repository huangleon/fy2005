//mac's chuxun.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","��Ѳ��");
  set("long",@LONG
�˸󰴶�����۳�Ѳ�ĳ������ã�ǰ����ʿ��ʮ��ѧʿ��������۳���������
����������߸�Ϊ���˴�Σ���������Ϊ���鹫����������Ϊ���ҹ�����ǰ�غ�ӵ
������ٹ��⣬�м仹���ֶӣ����̡���ǰ����ҹ�����࣬���ۿ�����
LONG
  );
  	set("exits",([
         	"east":__DIR__"renan",
         	"north": __DIR__"w_bei",
         	"west": __DIR__"xihua",
               ]));
        set("objects", ([
                __DIR__"npc/tong":	1,
                
       	]) );
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

int valid_leave(object who, string dir) {
	object wei;

		if (who->query("class") == "demon")
		return 1;

	if (dir =="east" || dir =="north") {
		if (wei = present("tong wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"�ȵ������������answer��\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"�ȵ���С�ӣ�ɱ���˻�������\n");
		}
	}
	return 1;
}