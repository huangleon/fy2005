inherit ROOM;

void create()
{
	set("short", "�ӻ���");

	set("long", @LONG
����һ��СС���ӻ��̣����ܴ���С�������һ�أ�����һЩ�ճ���Ʒ������
�������������һֻ�����ϣ��к��Ź������ˡ���˵���ƹ�ĵ���Ҳ����Щ��ͷ��
��������ºŽ�ʲô��һ��硱���š����˽������Ҳ��һЩ���صĶ�����̯��
����һ�����ƣ�������
LONG);


	set("type","house");
	set("indoors", "fugui");
	set("exits",([
		"east":__DIR__"xiaojie2",
	]) );
	set("item_desc", ([
		"sign": @TEXT
    �����ΰ����ã�ɽ�����˺��С�
    �������Խ�������ͣӪҵ��
    ����֮�������λ�ַ��½⡣

TEXT
	]));
		
	set("objects",([
		__DIR__"npc/zhanggui":1,
	]));

	set("coor/x",10);
	set("coor/y",100);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
