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
	"northeast" : __DIR__"baiyunentrance",
	"southwest" : __DIR__"flowerroad",
	// 	     "east"  : __DIR__"beach2",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",-10);
    set("coor/y",-30);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
