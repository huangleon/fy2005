inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
�����˼�ϡ�٣�����������˹�ˡ�����������һ����������������ϱ���һ
��Ƭ���֣���ľ���죬��ɭɭ�����㲻�����롣˵��������ʲôǿ������Ұ��ð��
���أ��㲻���ӿ��˽Ų���ǰ����Լ����������˵����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 //"east" : "/u/hangzhou/road0",
	  "west" : __DIR__"fysouth",
	  "northeast": __DIR__"sroad5",
]));
        set("outdoors", "fengyun");
	set("coor/x",100);
	set("coor/y",-320);
	set("coor/z",0);

	setup();
}

