class CreatePhotos < ActiveRecord::Migration
#  def change
#    create_table :photos do |t|
#
#      t.timestamps
#    end
#  end

  def self.up
    create_table "photos" do |photo|
        photo.column "filename", :string
    end
  end

  def self.down
    drop_table "photos"
  end
end
