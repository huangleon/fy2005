//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
����ϰϰ��΢΢��Щ��ζ֮�м����˱ǻ��㣬ԶԶ��ȥ���������۵�С��������
�дУ�һ���̡�һ�ź졢һ�Żơ�һ���ϣ��˵��Ƿ����ƽ�����Ӣ�ͷס����Ƶ�����
��֮�ˣ�����ůʪ����ľ���̣����ݷ�ï�������Ͽɰ�����Ů���ǽ������ɰ�������
��������������˱Ȼ��㡣
LONG
    );
    set("exits",
      ([
	"northeast" : __DIR__"flowerroad2",
	"southup" : __DIR__"maze8",
      ]));
    set("objects",
      ([
		__DIR__"npc/flowergirl" : 1+random(3),
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-20);
    set("coor/y",-40);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
