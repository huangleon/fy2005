#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", CYN"��ϼ��ѩ"NOR);
  set ("long", @LONG
���������ߴ�϶��б�ս�����ӳ����ө������ŵĵ�㸡�����������Ÿ�����
Ů�ӣ���������յ�ٽѾƱ���ϸ�����������״ɣ�ӯӯһ����ָ�䣬������ת��
�������������������޵İ����㣬����˹�����ģ�С���������ˮС¥����������
ϼ֮��һ���ѩԭ���ߡ�
LONG);
        set("exits", ([ 
  "down" : __DIR__"enterance",
]));
		set("objects", ([
			__DIR__"npc/gorcer" :1,
//			__DIR__"npc/hex" :1,
//	"/d/bashan/npc/so":1,
	]) );

  	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",100);
	setup();
  replace_program(ROOM);

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
