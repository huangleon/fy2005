// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�ؾ�¥");
        set("long", @LONG
�����ӻҳ����ƺ����������������ݶ��Ǿ���������¥���вؾ�¥����������
��������Ҳ�ѽ��룬����ǽ���Ͻ������ľ����ഫΪ�����Զ��ʦ�������÷���
���ڡ�����ѧ֮�еĲ������š�
LONG
        );
        set("exits", ([ 
  "down": __DIR__"cj5",
]));
        set("objects", ([
                __DIR__"npc/killera" : 1,
                __DIR__"npc/killerb" : 2,
                __DIR__"obj/xisuihe" : 3,
       ]) );
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",70);
	set("no_fly",1);
	set("no_lu_letter",1);
	setup();

}
