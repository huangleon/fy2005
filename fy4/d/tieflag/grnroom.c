#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",GRN "����"NOR);
  set("long",@LONG
һ���ݣ����Ȼ�����Ҳ���һ���½ŵĵط������������˸�ʽ�����Ļ��ݣ���
�д󲿷��㶼�в��������֡�������Щ�������εĲ�ľ���㶼�̲�ס��Ҫ����һ��
���ǡ�
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/grngirl" : 1,
       ]) );
  
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
 }
