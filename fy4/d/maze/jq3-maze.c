// silencer@fy4 workgroup 


inherit VRM_SERVER;

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room(__DIR__"jq3-room");

	//�Թ��ĳ��Ϳ� (5-100)
	set_maze_long(30,30);
	
	//�趨�Թ���λ�����
	set_maze_spacing(5);

	//�Թ��������npc.
	//note: this one is optional
//	set_maze_npcs(__DIR__"npc/w-sentry-1");

	//�Թ������ڷ��� npc �Ŀ�����(1-100)
	//note: this one is optional too, if not set, then default is 20 (1/5)
//	set_maze_npc_rate(100);

	//�Թ��ؽ�ʱ�� pass in integer ����Ϊ��λ
	//note: this one is optional, if not set then default is no refresh
	//if pass in 0, then means no refresh too.
	// this example means maze will be refreshed in 1 hour.
//	set_maze_refresh(86400);

	//��ڷ���(�����ڶ���)
	set_entry_dir("west");

	//�������������ӷ���
	set_link_entry_dir("west");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"jq3-entry");
	
	//��ڵ�����(��������link_entry_room���Ǹ���ʵroom������
	set_link_entry_room_x(-10);
	set_link_entry_room_y(-9);
	set_link_entry_room_z(10);
	

	//��������������ӷ���
	set_link_exit_dir("east");

	//��������������ӵ�����
	set_link_exit_room(__DIR__"jq3-exit");

	//��ڷ��������
	set_entry_short("������");

	//��ڷ�������
	set_entry_desc(@LONG
��֮�ڴ�����˶��ԣ����������������Ϊ��Ҫ�������в���������ƶ���� 
�������ƣ���һ���������֣�����ʲô�˲��ᱻ�򵹵��أ���������Ľ��ͺ����� 
�����������Ů���ˣ�������Ϊ��һ�������� 
LONG
);

	//���ڷ��������
	set_exit_short("�ƽ���ǰ");

	//���ڷ�������
	set_exit_desc(@LONG
���಻�ϵĵ���ת����ͷ�����ͣ��޾��ĲƸ������ֵĵ�λ���������书��
�����Ů�飬������˭�ܾ��������������ջ󣿲�֪������ǰ��Ȼ����������һ
�����ĸ�������������������ڿյ��ϡ�
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short("������");

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(@LONG
��Ǯ��֮�����ڳ�Ұ�������������Ϊ��Ǯ��ｨ���Ӵ�ļ�Ժ���ĳ� 
�����������ų��ڵĵ�Ȩ����ٸ��������ҶԽ�Ǯ�������춯����Ϊ˭������ 
�����ͷ�������϶��Ͳ�������ڶ���ĳ�����
LONG
);

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(0);
}
