inherit ROOM;

void create()
{
	set("short", "ӥ���̺�");
	set("long", @LONG
ӥ��һ��������׿�������ⶦʢ���̺š���Ȼ���ڻ����¶��ң��������⻹��
������һ�����֣��Ӳض������Ĳ��㣬�ӹ��������Ĵ�����˿�У��Ӵ��¯������
��ש������ʲô��ֻҪ�Ǽ�ֵǮ�Ķ�����������������������������̨�Ϸ���һ��
���ӣ��ӣɣǣΣ���
LONG
	);
      	
	set("item_desc", ([
		"sign": @TEXT
���̺Ų����ۺ񡣿��Ŀ��������
convert     �һ�Ǯ�ҡ�
withdraw    ��ȡ��
deposit     ����Ǯ�ҡ�
balance     ��Ѱ��
loan        ��Ǯׯ��Ǯ��
pawn	    �䵱��
sell	    ���ϡ�
value	    ���ۡ�
redeem	    ��ء�
TEXT
	]) );
	set("exits", ([
		"west" : __DIR__"octo15",
	]));
        set("objects", ([
                __DIR__"npc/hu": 1, 
		__DIR__"npc/petowner" : 1,
		]));
	set("coor/x",40);
	set("coor/y",30);
	set("coor/z",0);
	setup();

}