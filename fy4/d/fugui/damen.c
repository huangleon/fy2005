inherit ROOM;

void create()
{
	set("short", "����ɽׯ����");
	set("long", @LONG
·����ͷ�������������µġ�����ɽׯ���Ĵ��š�էһ��ȥ���������ϵ�����
���ۼ���أ���֪�����Ŷ����ܹ��ɽ�����Ѫ������������Ϊׯ�����Ǹ����Թ�
֮�ˡ���ǰ���Ҹ�����һֻ����ׯ�ϵ�ʯʨ�ӡ�������ϸ�ƣ��������̾������ԭ
�������⼣�߰ߣ����ǻҳ�������Ҳ�Ѱ����룬Ī��֮�����˲���һ�������ĸ�
����
LONG);

	set("outdoors", "fugui");
	set("type","street");
	set("exits",([
        "southdown":__DIR__"shandao1",
        "enter":__DIR__"suishilu1",
	]) );
	set("bandit_out",1);
	set("coor/x",10);
	set("coor/y",190);
	set("coor/z",80);
	setup();
	replace_program(ROOM);
}

/*
void init() {
	int i;
	i=sizeof(query("coor"));
	message_vision("size of coor is"+(string)(i)+".\n",this_player());
}
*/