//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIC"������"NOR);
    set("long", @LONG
������԰����޹��İ���ع����ģ�է����ů������ˮ���۶��������ۿ�������
��Ⱦ��������塣�Ǵ���������μˣ�����Я���֡�ǲ���ˡ��Լξ�����Ŀ�˻���
���ɸоɡ���á��۳ǵ��գ�����ҹ�򣬰����®�����󴺷磬ʮǧ���ơ�δʡ����
���������ң����ﲻѰ��������֪��¥���������ϣ�ǰ������ż��
             ���źޣ������磬һ����������մ���䡣
LONG
    );
    set("exits",
      ([
	"out" : __DIR__"skystreet4",
	"up":  __DIR__"yaoxian",
      ]));
    set("objects",
      ([
	__DIR__"npc/wangxian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
