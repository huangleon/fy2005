inherit ROOM;
void create()
{
        set("short", "��վ");
        set("long", @LONG
��һ��쳾����Ц������֪����֦������������ʫ�䣬��������д���ƴ���վ
�Ŀ��ﴫ�͡���ʵ��վ�����ݵ��ܴ�������֮ʱ������ʱ��ר�ŵľ�����վ����
Ϊ�������̡��������վ������̡��䱤��̫ƽ��Զ���˰�������ϡ�٣������վ
���˵�����ߵĹټ���������ة���ǰ�ʮ�������յĸ�ĸ�١�
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"mroad1",
		"east": __DIR__"xiangfang",
		"north": __DIR__"stable",
	]));
        set("objects",([
                       __DIR__"npc/anzihao" : 1,
                      ])  );
           

        set("item_desc", ([
	
	 ]));
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
