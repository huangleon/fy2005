// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
͸���谵�Ĺ��ߣ������ڿ�������Χ�Ļ�����ɽ����û�����������ô��ֻ
������ĵ�·ʮ�����ۣ��ںڰ��и����Դ����ǽ���ϻ���ͭ���ıڵƣ���Զ����
һ�Ѱ׹ǣ���֪��ʲô������û���ӳ��ص������������ڴˣ����������ﰵ��Ϊ��
�����ң���Ҳ�е���ǰ;�ļ��ѡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"lmidao2",
]));
	set("coor/x",90);
	set("coor/y",30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
