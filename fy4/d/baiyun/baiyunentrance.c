//Sinny@fengyun
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���Ƶ����");
    set("long", @long
�㼫ĿԶ�����������Ƶ����ʮ������ĵش���ľ���죬����ԭʼɭ�֡�ɽ��
͹������������¥������ع��㣬ԶԶ���������˼��ɾ�������������������
������������ʮ�㡣С�������ʯ��ᾣ������Ļ�����ʯ���ƣ������Ѱ�������ȴ��
�ٻ����ޣ��̲ݸ��أ�ɷ�Ǻÿ�������������������ƣ���������ν֮���Ƶ���
long
    );
    set("exits", 
      ([ 
	"southwest" : __DIR__"flowerroad2",
	"southeast" : __DIR__"pailangya",
	"north" : __DIR__"huangsha1",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/xiu1" : 1,
	__DIR__"npc/xiu2" : 1,
	__DIR__"obj/grass": 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-20);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
