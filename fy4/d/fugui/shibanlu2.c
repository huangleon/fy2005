inherit ROOM;

void create()
{
	set("short", "��ʯС·");

	set("long", @LONG
������ʯС·������һ����԰�����ױ��Ǹ�����������·����������̦��һ��
���ľͻ���������಻֪����Ұ�����õ�Ҳïʢ��������ɢ����һ�����µĻ��㡣
�����ż������һ������Ľ�����һ̧ͷ�����Կ��������������״��������ӥ
״�ķ��ݸ߸߷�������������С�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"east":__DIR__"liyuan",
		"west":__DIR__"fuguitin",
	]) );
        set("objects" , ([
	    __DIR__"obj/flower" : 1,
        ]));
	set("coor/x",20);
	set("coor/y",210);
	set("coor/z",80);
        setup();
}
/*
int valid_leave(object me, string dir)
{
    if (!wizardp(this_player()) && (dir=="west" || dir=="east"))
         {
           if( random((int)this_player()->query("kar")) < 2 )
              {
               message_vision("$Nһ�Ų�����̦��, ��С�Ļ���һ��, �Ľų����ˤ�ڵ���������\n\n\n", this_player());
               this_player()->unconcious();
              return 0;
              }
           else return 1;
         }
     else return 1;
}
 */ 