inherit ROOM;
void create()

{
	set("short", "��ӭ���ٷ�������");
	set("long", @LONG
һ���׹��������㷢���Լ���Ȼ������һ��İ���ĵط�������ܸߣ������Ƽ䣬
���¿�������������ˮ�����Ľֵ���Ī���Ǿ��Ǵ�˵�еķ��Ƴǣ���������һ��ľ
�ƣ�Ҳ����Ӧ�ÿ�һ��������롡������
LONG
	);
	set("exits", ([
  		"down" :  __DIR__"newbie1",
	]));
	set("item_desc", ([
		"sign": "
���뿴����������(l, look),����֪����������ﶼ��˭(who),
������Ҫ�Ĵ����ߣ�(w,s,n,e,nw,ne,,sw,se,d,u,sd,nd,wd,ed,wu,nu,eu,su)��
��������ȿ�������Щ���ڡ�
��������new�ӿո�Ȼ���ټ���Ҫ˵�Ļ������졣\n"
	]));
	
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",1000);
	set("no_magic",1);
	set("no_fight",1);
	setup();
}
