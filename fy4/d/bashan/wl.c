
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIG"������"NOR);
    set("long", @LONG
�ط�ɽׯ����ɽׯ����Ȼ����ɽ�ϡ�ɽ�ƽ�̧������ɽׯ�е�·���У���Զ��
����СС�ɸ�����������е�����������ǰ�ˣ��˵�����������֮���������£�
ȴ�Ͳ���������ߡ����켴�ǹ˵��˷⽣����֮�գ������и��Ÿ��ɶ�����������
��ʾ�羴��СС�������������������������ˣ��������֡�
LONG
    );
    set("exits",([
	"northdown" : __DIR__"hf",
      ]) );
    set("objects", ([
	__DIR__"npc/man1" : 1,
	__DIR__"npc/man2" : 1,
	__DIR__"npc/blademaster" : 1,
	__DIR__"npc/man3" : 1,
	__DIR__"npc/man4" : 1,
	__DIR__"npc/stormeye" : 1,
	__DIR__"npc/man5" : 1,
	__DIR__"npc/app2" : 1,
	__DIR__"npc/gu" : 1,
      ]));

    set("no_fly",1);
    set("coor/x",20);
    set("coor/y",-20);
    set("coor/z",20);
    setup();
}


/*

//update /d/bashan/npc/man1;update here;l
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


