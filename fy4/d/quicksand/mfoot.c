
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
[33mɳĮ[32m���������ƺ��Ѿ������ߵ�ɽ�Ե�ס�ˡ����ۿ����ô������ĮҲ������
��չһ����������ȻҲ�ǹ�ͺͺ�ģ������Ѿ����������˵Ŀ��ȡ����걻�������
�����Ѿ����������¸�������������ɽ����[33m����[32m�˾�ס�ĵط�������������������
����ͷ��ɳ��ͨ��[33m�½�[32m����˵˿��֮·���Ǵ������ʼ�ġ�����
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"desert10",
  "northwest" : __DIR__"skyroad1",
  "west" : __DIR__"mroad",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1110);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

