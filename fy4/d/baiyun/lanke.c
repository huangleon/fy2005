//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "�ÿ²���");
    set("long", @LONG
����ֻ�Ǹ���ª�Ĳ��ã�ûʲô���裻����������һ�����ӣ������ƾɲ�������
����ĺ����л������������ͣ��ȴ��ôҲ���������������������ˮ��ע���ƣ���
���������࣬���г�ʱ���������ʷ�ľ��ʯ���У���ͯ�����˵��ٶ��裬�����п���
֮����ͯ���ƣ������Ѿã��ɻ�����ȡ���������þ������ң����������ꡣ����ν��

               ��������ս        �˼����Ƿ�
               �սк��Կ�        �ÿ²�֪��

LONG
    );
    set("exits",
      ([
	"east" : __DIR__"skystreet3",
      ]));
    set("objects",
      ([
	__DIR__"npc/zhongpu" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
