//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "����ͤ");
    set("long", @LONG
��һ���ط��൱����������������涼�Ǹ��ߵ�ʯ�ڣ�����Ȼ�ڴ�ʯ��֮�У�
���ս�����һ����ͤ��ͤ���·�������ӿ���ȵĺ��˼�������ʯ��Ҳ�����ܺ�ˮ��ʴ
��ǧ���ٿף���̦�ܲ�������ͤ�к��������򺣶��գ�����������ʱ����˵���Ƴ���
����������˹۳����գ�������ˡ�
LONG
    );
    set("exits",
      ([
	"northdown" : __DIR__"pailangya",
	"southeast" : __DIR__"jianlin",
      ]));
    set("objects",
      ([
	__DIR__"npc/xiu3" : 1,
	__DIR__"npc/xiu4" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-40);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}
