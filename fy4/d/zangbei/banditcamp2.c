inherit ROOM;

void create()
{
        set("short", "��Ȧ");
        set("long", @LONG
Ӫ������ľ��Χ��һ����Ȧ��Ȧ������ʮ��ƥ������Ҳ����һ����ƥƥ�ݹ�
��ᾣ�������������Ȼ��ȱ�����ϵ�Ե�ʣ��������������̵Ļ�ԭ�ϣ���ǿ��Ҳ��
��һ�����׵��е���
LONG
        );
        set("exits", ([ 
	  	"southeast" : __DIR__"banditcamp1",
	  	"west" : __DIR__"banditcamp3",
			]));
	set("objects", ([

	]));
	set("outdoors", "zangbei");

        set("coor/x",-450);
	set("coor/y",620);
	set("coor/z",0);
	set("map","zbeast");
	setup();
}

