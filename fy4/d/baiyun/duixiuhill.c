//Sinny@fengyun 2003 
//All Rights Reserved 
inherit ROOM;
void create()
{
    set("short", "����ɽ");
    set("long", @LONG
��ǽ������ʯɽǡ�ơ����㡱��ɽ���վ���������ͣ���Ϊ��ӱ��ɽʯ��������
��ͬ�Ķ��ݼ��ɣ����е�������ʯ�����г�Ⱥ��ɽ�ͣ��¹Ⱦ��ͣ��������䣬ͬ��Χ
�Ľ���������ϣ������Ի��������ɵ�ӡ��
LONG
    );
    set("exits",
      ([
	"northwest" : __DIR__"emaze1",
	"southup" : __DIR__"hillroad",
	// 	     "west"  : __DIR__"beach1",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([ 
	__DIR__"obj/shanshi" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-90);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}
