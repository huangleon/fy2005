// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "ǧ������");
    set("long", @LONG
�߽��˴���ֻ����ɽ��ˮȫȻ��ȥ����������Ũ�������˷���ӿ��
����գ�ۼ�ͽ�����ߵ�������û�����߿ɼ�֮�����޲���һƬãã������
������·Ҳ��ʧ�������ǰ���ǽ������ˣ���ֹס�Ų����Ĺ�ãȻ��
LONG
    );
    set("objects", ([
	__DIR__"npc/gongsun" : 1,
      ]));
    set("exits",([
	"east" : __DIR__"liangjie",
	"west" : __DIR__"jieyu",
      ]) );
    
    set("outdoors", "xiangsi");
    
    set("coor/x",-5);
    set("coor/y",0);
    set("coor/z",0);
    setup();
}

int	valid_leave(object who, string dir)
{
    tell_object(who,CYN"���������ƣ�С������Ĵ�������ǰ�С�\n"NOR);
    if (userp(who))	who->perform_busy(1);
    return ::valid_leave(who,dir);
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

