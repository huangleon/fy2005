inherit ROOM;
void create()
{
        set("short", "С���϶�");
        set("long", @LONG
��������û��·��������������ׯ԰��̫ƽ���ʮ�����˼ң�һ��������ɽ
����ү�ģ���һ����������ġ�û����֪������������ʲô��Ҳû��֪��������
����ֻ֪��������ǰ����������ׯ԰�����ɸ�ǽ�ϵ����ŷ��У�ׯԺ������һ��Ī
����������ɭ֮�С�
LONG
        );
        set("exits", ([ 
		"north": __DIR__"mroad7",
		"southeast": __DIR__"mroad9",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"door":	"��ڵĴ��Ž����ع��š�\n",		    
		"����":	"��ڵĴ��Ž����ع��š�\n",
	]));
	set("coor/x",-20);
	set("coor/y",-80);
	set("coor/z",0);
	set("map","taiping");
	setup();
	
}

