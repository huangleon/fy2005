#include <room.h>
inherit ROOM;

void create()
{
  	set("short","������");
  	set("long",@LONG
����������ؽ��󹩻ʵ۳�ɽʱפ�ϣ�����פ��ͤ�������ڶ������ڣ��ʽ��
�������������ɴ����š����š����š�������᷿��ɡ��������������ţ������
����Ķ����š�
LONG
  );
  	set("exits",([
        	 "west":__DIR__"dongyu",
         	 "east":__DIR__"donghua",
         	 "north": __DIR__"e_bei",
         	 "south": __DIR__"hanbaiting",
        ]));
        set("objects", ([
                  __DIR__"npc/tie":	1,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	
}

int valid_leave(object who, string dir) {
	object wei;

		if (who->query("class") == "demon")
		return 1;

	if (dir == "north" || dir =="south" || dir == "west") {
		if (wei = present("tie wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"�ȵ������������answer��\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"�ȵ���С�ӣ�ɱ���˻�������\n");
		}
	}
	return 1;
}