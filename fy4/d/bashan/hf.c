
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", YEL"�ط�ɽׯ"NOR);
    set("long", @LONG
����С��ɽ�ŷ��ֻ�����ٳ�֮ң��������һ����ŷ��������ͥԺ��ͥԺ��
��ȥ������˼Ҳ�û��ʲô���ȴ��������һ��ʥ�أ���Ϊ�����ǻط�ɽׯ����
�ط�ɽׯ��ׯ�������Ƕ�ʮ��ǰ��һ�ֻط��������������������������������ʮ
����ɽկ�Ĺ˵��ˣ���ɽ���͹˼��
LONG
    );
    set("exits",([
	"southup" : __DIR__"wl",
	"northdown" : "/d/xiangsi/jieyu",
      ]) );
    set("objects", ([
	__DIR__"npc/hfguard1" : 1,
	__DIR__"npc/hfguard2" : 1,
      ]));

    set("no_fly",1);
    set("coor/x",20);
    set("coor/y",-10);
    set("coor/z",10);
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

