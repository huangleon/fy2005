
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ԭ������ıؾ�֮·���������Կ���һ���ƾɵĳ��ǣ����������
�����ں���ĺۼ����������������նӴ����ﾭ�����γ���һ��СС��[33m����[32m����֪
Ϊʲô���������ȴ�������������̶���ͣ����ЪЪ�ţ��������˼����˼ҡ�
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"sandroad",
  		"west" : __DIR__"oldgreatwall",
 		"south": __DIR__"fair",

]));
        set("outdoors", "quicksand");
        set("objects", ([
                
        ]) );

	set("coor/x",-1030);
	set("coor/y",0);
	set("coor/z",0);
	setup();

}

