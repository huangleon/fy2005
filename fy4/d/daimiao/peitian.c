
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
�������ȡ����֮�������ء�֮�⡣������������䣬�������䣬Ъɽ����
ǰ����ʽ���ö������������������׻�����ȸ��������ķ����޵�����������
������ϵĶ�����������д���������������֡��򶫿�������Ժ���������껨��Ժ��
LONG
  );
  	set("exits",([
         	"north":__DIR__"renan",
         	"south":__DIR__"zhengyan",
         	"east" :__DIR__"sanling",
         	"west" :__DIR__"taiwei",
               ]));
        set("objects", ([
                 __DIR__"npc/yin":	1,
       	]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}



int valid_leave(object who, string dir) {
	object wei;

		if (who->query("class") == "demon")
		return 1;

	if (dir == "north" || dir =="east" || dir == "west") {
		if (wei = present("yin wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"�ȵ������������answer��\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"�ȵ���С�ӣ�ɱ���˻�������\n");
		}
	}
	return 1;
}

	