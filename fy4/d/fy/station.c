#include <ansi.h>


inherit ROOM;
void create ()
{
  set ("short", WHT"������"NOR);
  set ("long", @LONG
���ϳ�����Ƿ���ˮ�����ڼ���ǰ��Ϊ����Υ�´�����������������٣�
һ��û���˹��޵Ľ������˾;���һ�����飬�����ǧ����������ɽ����ֳ����
���ؽ��ķ��Ƴ���������������֮������һ�����ؽ���һ��ӯ���˻����������
�ݣ�ͨ�������µļ�԰��
LONG);
        set("exits", ([ 
  "east" : __DIR__"yundoor",
  "up" : "/p/residence/enterance",
]));
  	set("no_fight",1);
  	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}
