#include <room.h>
inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
����Ҳ�ƽ��ã�����˵�𷨼���֮�أ��м�Ϊʨ��������ǰΪ���Σ���Ϊ������
����Ϊ�����𷨵�ʨ��ͼ����������������������ϯ�ϣ�������ӣ��ұ���С�ģ�
Ϊ����˵��ʱ��֮��
LONG
  );
  set("exits",([
            "east":__DIR__"mile.c",
               ]));
        set("objects", ([
                __DIR__"npc/bonze4" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
