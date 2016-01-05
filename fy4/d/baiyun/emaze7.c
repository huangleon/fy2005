#include <ansi.h>

inherit ROOM;
string *names=({
  __DIR__"emaze8",
  __DIR__"emaze4",
  __DIR__"emaze2",
  __DIR__"emaze3",
} );
void create()
{
    set("short", GRN"ʯɽ"NOR);
    set("long", @LONG
�Ĵ���ʯɽǡ�ơ����㡱��ɽ���վ���������ͣ���Ϊ��ӱ��ɽʯ�������˲�
ͬ�Ķ��ݼ��ɣ����е�������ʯ�����г�Ⱥ��ɽ�ͣ��¹Ⱦ��ͣ��������䣬ͬ��Χ
�Ľ���������ϣ������Ի��������ɵ�ӡ�󡣵��˼�ļ�ɽ��ٴ��䣬�������ң�
һ��С�ģ�����ʧ�˷���
LONG
    );
    set("outdoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-70);
    set("coor/z",10);

    setup();
}
void reset()
{
    int i,j;
    string temp;
    ::reset();
    for (i=0;i<=3;i++)
    {
	j=random(4);
	temp=names[j];
	names[j]=names[i];
	names[i]=names[j];
	names[i]=temp;
    }
    set("exits", ([
	"north" : names[0],
	"south" : names[1],
	"east" : names[2],
	"west" : names[3],
      ]));
}

