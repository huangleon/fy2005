#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short","С��");
  set("long",@LONG
�������뿪�˹���ľ������磬�����������ƺ��С��С�ݡ��ɸɾ����·�һ
����Ⱦ������û���κΰ��裬һ�����ŵ�ֱ���Ե÷�����Ŀ����ֱ�������ŵķ���
�����������������ļ��������޵������еĶ��������
LONG
  );
  	set("exits",([
       	 "down":__DIR__"houqing",
        ]));
	set("objects", ([
			  __DIR__"npc/feng":	1,
	]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",20);
	setup();
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

