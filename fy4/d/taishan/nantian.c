inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ǵ���������ؾ��������ţ���ǰһ��Ħ���Ρ��ׯ�أ����Ʋ���������
ʯ�̣��������������񹤣��ĸ���ľ�������䱥�����꣬ȴ��ɫ���ģ��ٷ�Զ����
����������������һ��Х����������������ɴ����ϣ��㵽��̩ɽ�ĺ�ɽ����ʯ
����������̩ɽɽ���ϼԪ�������˼乩��֮���ڣ���������������µĹ��·塣
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"shiba",
  "west" : __DIR__"shanfeng",
  "north" : __DIR__"houshi",
  "east" : __DIR__"bixia",
]));

        set("item_desc", ([
                "ʯ��": "		
		��		��
		��		��
		��		��
		��		��
		��		��
		��		��
		ǧ		��
		��		��
		��		ʤ
		��		��
		 ��		 ��			
"        ]) );
        set("objects", ([
        __DIR__"npc/pettrainer" : 1,
                        ]) );
        set("outdoors", "taishan");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",120);
	setup();
        replace_program(ROOM);
}
